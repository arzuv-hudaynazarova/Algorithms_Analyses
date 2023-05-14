# Algoritma Analyses and Desing ks2

# Ödev.c'nin açıklaması ve zaman karmaşıklığı:

Ödev.c de, belirli bir boyuttaki bir dizi üzerinde çeşitli işlemler gerçekleştiriyor. Öncelikle, kodun yapısını ve karmaşıklığını anlamak için her bir fonksiyonu ayrı ayrı yazalım.

1. diziOlustur: Bu fonksiyon, belirli bir boyuttaki bir dizi oluşturur ve bu diziye rastgele sayılar atar. Karmaşıklık O(n) olarak hesaplanır çünkü her bir eleman üzerinde sadece bir işlem gerçekleştirilir.

2. hizliSiralama ve bolme: Bu fonksiyonlar, QuickSort algoritmasını uygulayarak bir diziyi sıralar. QuickSort algoritmasının ortalama karmaşıklığı O(n log n), kötü durum karmaşıklığı ise O(n^2)'dir. Ancak pratikte kötü durumun oluşması nadirdir ve genellikle O(n log n) karmaşıklık gözlemlenir.

3. toplamiBul: Bu fonksiyon, dizideki elemanların toplamını hesaplar ve bu toplamı eleman sayısına böler. Bu işlemi gerçekleştirmek için tüm elemanlar üzerinde bir kez geçilir, bu yüzden karmaşıklık O(n)'dir.

4. enKisaYoluHesapla: Bu fonksiyon, Floyd-Warshall algoritması kullanarak bir grafın tüm çiftler arasındaki en kısa yollarını hesaplar. Bu algoritmanın karmaşıklığı O(n^3)'tir, çünkü her çift düğüm arasındaki en kısa yol hesaplanmalıdır ve bu da n düğüm için n^2 çift anlamına gelir.

5. sonucYazdir: Bu fonksiyon, t değerinden küçük olan tüm yolları yazdırır. Karmaşıklık O(n^2)'dir çünkü her çift düğüm için kontrol yapılır.

Sonuç olarak, bu kod parçasının en büyük zaman karmaşıklığı, Floyd-Warshall algoritmasının uygulandığı enKisaYoluHesapla fonksiyonunda bulunan O(n^3)'tir. Diğer fonksiyonların karmaşıklıkları daha düşüktür.



